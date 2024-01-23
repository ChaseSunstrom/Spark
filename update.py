import os
import requests
import zipfile
import shutil
import sys
import stat
from packaging import version


def get_local_version(spark_dir):
    version_path = os.path.join(spark_dir, 'version.txt')
    if not os.path.isfile(version_path):
        return '0.0.0'  # Default to version 0.0.0 if version file does not exist
    with open(version_path, 'r') as file:
        local_version = file.read().strip().split()[1]
    return local_version


def download_and_extract_repo(github_repo, temp_dir):
    repo_url = f'https://github.com/ChaseSunstrom/Spark/archive/refs/tags/pre-release.zip'
    response = requests.get(repo_url)
    if response.status_code != 200:
        print(f"Failed to download the repository. Status Code: {response.status_code}")
        sys.exit(1)

    zip_path = os.path.join(temp_dir, 'master.zip')
    with open(zip_path, 'wb') as file:
        file.write(response.content)

    with zipfile.ZipFile(zip_path, 'r') as zip_ref:
        zip_ref.extractall(temp_dir)

    os.remove(zip_path)

    extracted_dir_name = [name for name in os.listdir(temp_dir) if os.path.isdir(os.path.join(temp_dir, name))][0]
    extracted_path = os.path.join(temp_dir, extracted_dir_name)
    return extracted_path


def on_rm_error(func, path, exc_info):
    os.chmod(path, stat.S_IWRITE)
    if os.path.isdir(path):
        os.rmdir(path)
    else:
        os.unlink(path)


def update_spark_if_newer(spark_dir, temp_dir, github_repo):
    extracted_path = download_and_extract_repo(github_repo, temp_dir)

    downloaded_version_path = os.path.join(extracted_path, 'version.txt')
    if not os.path.isfile(downloaded_version_path):
        print("The version.txt file does not exist in the downloaded Spark repository.")
        sys.exit(1)

    with open(downloaded_version_path, 'r') as file:
        downloaded_version = file.read().strip().split()[1]

    local_version = get_local_version(spark_dir)

    if version.parse(downloaded_version) > version.parse(local_version):
        print(f"Updating Spark from version {local_version} to {downloaded_version}.")

        if os.path.isdir(spark_dir):
            shutil.rmtree(spark_dir, onerror=on_rm_error)
        shutil.move(extracted_path, spark_dir)

        print("Spark has been updated successfully.")
    else:
        print(f"Local Spark is up to date with version {local_version}.")
        shutil.rmtree(extracted_path)


if __name__ == "__main__":
    spark_dir = 'C:/Spark'
    temp_dir = 'C:/SparkDownloadTemp'
    github_repo = 'ChaseSunstrom/Spark'

    os.makedirs(temp_dir, exist_ok=True)
    update_spark_if_newer(spark_dir, temp_dir, github_repo)

    if not os.listdir(temp_dir):
        os.rmdir(temp_dir)

import os
import requests
import zipfile
import shutil
import sys
import stat
from packaging import version

def get_latest_release_tag(github_repo):
    api_url = f"https://api.github.com/repos/{github_repo}/tags"
    response = requests.get(api_url)
    if response.status_code == 200:
        tags = response.json()
        if tags:
            # Assuming the latest tag is the first one in the list
            latest_tag = tags[0]['name']
            return latest_tag
        else:
            print("No tags found in the repository.")
            return None
    else:
        print(f"Failed to fetch tags. Status Code: {response.status_code}")
        return None

def get_version_from_file(file_path):
    if os.path.exists(file_path):
        with open(file_path, 'r') as file:
            content = file.readline().strip()
            version_number = content.split()[1]
            return version.parse(version_number)
    return version.parse("0.0.0")

def download_and_extract_repo(github_repo, temp_dir, tag_name):
    repo_url = f'https://github.com/{github_repo}/archive/refs/tags/{tag_name}.zip'
    response = requests.get(repo_url)
    if response.status_code != 200:
        print(f"Failed to download the repository. Status Code: {response.status_code}")
        sys.exit(1)

    zip_path = os.path.join(temp_dir, 'download.zip')
    with open(zip_path, 'wb') as file:
        file.write(response.content)

    with zipfile.ZipFile(zip_path, 'r') as zip_ref:
        zip_ref.extractall(temp_dir)
    os.remove(zip_path)

    extracted_dir_name = [name for name in os.listdir(temp_dir) if os.path.isdir(os.path.join(temp_dir, name))][0]
    extracted_path = os.path.join(temp_dir, extracted_dir_name)
    return extracted_path

def update_spark_if_newer(spark_dir, temp_dir, github_repo):
    tag_name = get_latest_release_tag(github_repo)
    if not tag_name:
        print("Unable to get the latest version tag.")
        return

    extracted_path = download_and_extract_repo(github_repo, temp_dir, tag_name)

    if version.parse(tag_name.lstrip('v')) > get_version_from_file(os.path.join(spark_dir, 'version.txt')):
        print(f"Updating Spark to version {tag_name}.")
        if os.path.exists(spark_dir):
            try:
                shutil.rmtree(spark_dir)
            except PermissionError as e:
                print(f"Error: Unable to delete {spark_dir}. Ensure the directory is not open or in use.")
                sys.exit(1)
        shutil.move(extracted_path, spark_dir)

        # Update the version.txt file
        version_file_path = os.path.join(spark_dir, 'version.txt')
        with open(version_file_path, 'w') as file:
            file.write(f"VERSION {tag_name.lstrip('v')}")

        print("Spark has been updated successfully.")
    else:
        print(f"Local Spark is up to date with version {tag_name}.")
        shutil.rmtree(extracted_path)

if __name__ == "__main__":
    spark_dir = 'C:/Spark'
    temp_dir = 'C:/SparkDownloadTemp'
    github_repo = 'ChaseSunstrom/Spark'

    os.makedirs(temp_dir, exist_ok=True)
    update_spark_if_newer(spark_dir, temp_dir, github_repo)

    if os.path.exists(temp_dir) and not os.listdir(temp_dir):
        os.rmdir(temp_dir)

#version 330 core
out vec4 FragColor;

in vec3 Normal;  
in vec3 FragPos;  
in vec2 TexCoord;
  
uniform vec3 light_pos; 
uniform vec3 light_color;
uniform vec4 color;
uniform vec3 view_pos;
uniform sampler2D text;

void main()
{
    // ambient
    //vec4 text = texture(tex, TexCoord);
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * light_color;
  	
    // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light_pos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * light_color;

    // specular
    float specularStrength = 0.5;
    vec3 viewDir = normalize(view_pos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * light_color; 
            
    vec4 result = vec4(diffuse + ambient + specular, 1.0) * (texture(text, TexCoord) * color);
    FragColor = result;
} 
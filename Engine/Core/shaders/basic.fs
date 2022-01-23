#version 330 core

out vec4 FragColor;
in vec3 vertexColor;
in vec2 TexCoord;

uniform sampler2D outTexture;
uniform bool bColor;
uniform bool bTexture;

void main()
{
	if(bTexture == false)
	{
		FragColor = vec4(vertexColor,1.0);
		return;
	}
	if(bColor)
		FragColor = texture(outTexture,TexCoord) * vec4(vertexColor,1.0);
	else FragColor = texture(outTexture,TexCoord);
}
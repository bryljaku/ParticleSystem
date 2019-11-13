// vertex shader
#version 330

uniform mat4x4 matModelview;
uniform mat4x4 matProjection;

layout(location = 0) in vec4 vVertex;
layout(location = 1) in vec4 vColor;

out vec4 outColor;

void main()
{
    vec4 eyePos = matModelview * gl_Vertex;
    gl_Position = matProjection * eyePos;

	outColor = vColor;

	float dist = length(eyePos.xyz);
	float att = inversesqrt(0.1f*dist);
	gl_PointSize = 2.0f * att;
}

// fragment shader
#version 330

uniform sampler2D tex;

in vec4 outColor;

out vec4 vFragColor;

void main()
{
	vFragColor = texture(tex, gl_PointCoord) * outColor;
}
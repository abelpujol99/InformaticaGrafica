#version 330

layout (triangles) in;
layout (triangle_strip, max_vertices = 9) out;

uniform vec3 offset;

void main(){

	for(int i = 0; i < 3; i++){
		gl_Position = gl_in[i].gl_Position + vec4(offset, 0f);
		EmitVertex();
	}	
	EndPrimitive();

	for(int i = 0; i < 3; i++){
		gl_Position = gl_in[i].gl_Position - vec4(offset, 0f);
		EmitVertex();
	}	
	EndPrimitive();

	for(int i = 0; i < 3; i++){
		gl_Position = gl_in[i].gl_Position;
		EmitVertex();
	}
	EndPrimitive();
}
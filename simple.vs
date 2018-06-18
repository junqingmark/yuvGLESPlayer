attribute vec3 aPos;
attribute vec2 aTexcoord;

varying vec2 vTexcoord;

void main()
{
    gl_Position = vec4(aPos, 1.0);
    vTexcoord = aTexcoord;
}
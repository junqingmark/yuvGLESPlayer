precision mediump float;

varying vec2 vTexcoord;

uniform sampler2D textureY;
uniform sampler2D textureU;
uniform sampler2D textureV;

void main()
{
    vec3 rgb;
    vec3 yuv;

    yuv.r = texture(textureY, vTexcoord);
    yuv.g = texture(textureU, vTexcoord);
    yuv.b = texture(textureV, vTexcoord);

    rgb.r = yuv.r + 1.4022 * (yuv.b - 128);
    rgb.g = yuv.r - 0.3456 * (yuv.g - 128) - 0.7145 * (yuv.b-128);
    rgb.b = yuv.r + 1.771 * (yuv.g - 128);

    gl_FragColor = vec4(rgb, 1.0);
}

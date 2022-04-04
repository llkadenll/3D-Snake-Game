#version 330

uniform sampler2D tex;

out vec4 pixelColor;

in vec2 i_tc;
in vec4 normalVector;
in vec4 viewerVector;
in vec4 lightVector;
in vec4 lightVector2;

void main(void) {

	vec4 mn = normalize(normalVector);
	vec4 mv = normalize(viewerVector);
	vec4 ml = normalize(lightVector);
	vec4 ml2 = normalize(lightVector2);

	vec4 kd = texture(tex, i_tc);
	vec4 ks = texture(tex, i_tc);

	vec4 mr = reflect(-ml, mn);
	vec4 mr2 = reflect(-ml2, mn);

	// calculation of the lighting model (phong model)
	float nl = clamp(dot(mn, ml), 0, 1);
	float nl2 = clamp(dot(mn, ml2), 0, 1);

	float rv = pow(clamp(dot(mr,mv), 0, 1), 25);
	float rv2 = pow(clamp(dot(mr2,mv), 0, 1), 25);

	pixelColor = vec4(kd.rgb*nl, kd.a) + vec4(ks.rgb*rv, 0) + vec4(kd.rgb*nl2, kd.a) + vec4(ks.rgb*rv2, 0);
}

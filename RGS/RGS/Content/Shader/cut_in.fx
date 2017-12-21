struct PS_INPUT
{
	float4 DiffuseColor       : COLOR0;
	float4 SpecularColor      : COLOR1;
	float2 TextureCoord0      : TEXCOORD0;
	float2 TextureCoord1      : TEXCOORD1;
};

sampler Texture : register(s0);
sampler Texture1 : register(s1);

float rate : register(c0);

float4 main(PS_INPUT PSInput) : SV_TARGET
{
	if (rate <= 0.0001f)
		discard;

	float4 source = tex2D(Texture, PSInput.TextureCoord0);
	float4 mask = tex2D(Texture1, PSInput.TextureCoord0);

	float min_alpha = rate - 0.4f;
	min_alpha = min_alpha <= 0.0f ? 0.0f : min_alpha;


	if (mask.r > min_alpha) 
	{
		source = lerp(source, float4(0, 0, 0, 0), (mask.r - min_alpha) / (rate - min_alpha));
	}

	return source;
}
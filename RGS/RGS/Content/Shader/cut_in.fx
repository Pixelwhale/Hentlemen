struct PS_INPUT
{
	float4 DiffuseColor       : COLOR0;
	float4 SpecularColor      : COLOR1;
	float2 TextureCoord0      : TEXCOORD0;
	float2 TextureCoord1      : TEXCOORD1;
};

sampler Texture : register(s0);
sampler Texture1 : register(s1);

float4 main(PS_INPUT PSInput) : SV_TARGET
{
	float4 source = tex2D(Texture, PSInput.TextureCoord0);
	float4 mask = tex2D(Texture1, PSInput.TextureCoord0);

	float gray = mask.r * 0.3f + mask.g * 0.59f + mask.b * 0.11f;
	if (gray > 0.8f)
		return float4(0, 0, 0, 0);

	return float4(1, 1, 0, 1);
}
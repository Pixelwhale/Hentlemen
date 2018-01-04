struct PS_INPUT
{
	float4 DiffuseColor       : COLOR0;
	float4 SpecularColor      : COLOR1;
	float2 TextureCoord0      : TEXCOORD0;
	float2 TextureCoord1      : TEXCOORD1;
};

sampler Texture : register(s0);			//texture
sampler Texture1 : register(s1);		//mask用

float rate : register(c0);				//描画部分
float alpha : register(c1);				//全体のAlpha

float4 main(PS_INPUT PSInput) : SV_TARGET
{
	float4 source = tex2D(Texture, PSInput.TextureCoord0);
	float4 mask = tex2D(Texture1, PSInput.TextureCoord0);

	if (mask.r >= rate)					//描画より大きい部分は捨てる
		discard;

	float min_alpha = rate - 0.4f;		//半透明空間0.4 最低部分を今する最大値から引く
	min_alpha = min_alpha <= 0.0f ? 0.0f : min_alpha;		//0より小さい場合は0にする

	source.a = alpha;					//全体の透明度

	if (mask.r > min_alpha)				//半透明最小値より大きいはLerpで透明度調整
	{
		float4 transparent = source;	//Lerpの色
		transparent.a = 0;
		source = lerp(source, transparent, (mask.r - min_alpha) / (rate - min_alpha));
	}

	return source;
}
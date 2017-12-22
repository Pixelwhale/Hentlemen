struct PS_INPUT
{
	float4 DiffuseColor       : COLOR0;
	float4 SpecularColor      : COLOR1;
	float2 TextureCoord0      : TEXCOORD0;
	float2 TextureCoord1      : TEXCOORD1;
};

sampler Texture : register(s0);			//texture
sampler Texture1 : register(s1);		//mask�p

float rate : register(c0);				//�`�敔��
float alpha : register(c1);				//�S�̂�Alpha

float4 main(PS_INPUT PSInput) : SV_TARGET
{
	float4 source = tex2D(Texture, PSInput.TextureCoord0);
	float4 mask = tex2D(Texture1, PSInput.TextureCoord0);

	if (mask.r >= rate)					//�`����傫�������͎̂Ă�
		discard;

	float min_alpha = rate - 0.4f;		//���������0.4 �Œᕔ����������ő�l�������
	min_alpha = min_alpha <= 0.0f ? 0.0f : min_alpha;		//0��菬�����ꍇ��0�ɂ���

	source.a = alpha;					//�S�̂̓����x

	if (mask.r > min_alpha)				//�������ŏ��l���傫����Lerp�œ����x����
	{
		float4 transparent = source;	//Lerp�̐F
		transparent.a = 0;
		source = lerp(source, transparent, (mask.r - min_alpha) / (rate - min_alpha));
	}

	return source;
}
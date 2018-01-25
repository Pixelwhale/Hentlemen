#pragma once

namespace Actor
{
	class BuffFunction
	{
	public:
		virtual void Damage(int damage) = 0;
		virtual void Heal(int healF, float healP) = 0;
	};
}
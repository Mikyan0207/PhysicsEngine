
PE_NAMESPACE_BEGIN

static constexpr PE_PI = 3.14159265358979323846f;

constexpr float DegreesToRadians(float v)
{
	return v * (PE_PI / 180.0f);
}

constexpr float RadiansToDegress(float v)
{
	return v * (180.0f / PE_PI);
}

PE_NAMESPACE_END

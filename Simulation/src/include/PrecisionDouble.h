#pragma once
#include <string>
#include <cmath>

class PrecisionDouble
{
private:
	double dec;
	double ex10;
public:
	PrecisionDouble();
	PrecisionDouble(double dec, double ex10);
	void SetEx10(double ex10);
	void SetDec(double dec);

	double GetDec() const;
	double GetEx10() const;
	double ToDouble() const;
	std::string ToString() const;

	void RemoveFractionEx10();
	PrecisionDouble NoFractionEx10() const;
	static PrecisionDouble NoFractionEx10(const PrecisionDouble& pD);

	static PrecisionDouble Normalize(double decimal, double exp10);
	static PrecisionDouble Normalize(double decimal);
	static PrecisionDouble Normalize(const PrecisionDouble& toNormalize);

	PrecisionDouble operator+(const PrecisionDouble& sec) const;
	PrecisionDouble operator-(const PrecisionDouble& sec) const;
	void operator+=(const PrecisionDouble& sec);
	void operator-=(const PrecisionDouble& sec);

	PrecisionDouble operator*(const PrecisionDouble& sec) const;
	PrecisionDouble operator/(const PrecisionDouble& sec) const;
	PrecisionDouble operator^(const PrecisionDouble& sec) const;
	void operator*=(const PrecisionDouble& sec);
	void operator/=(const PrecisionDouble& sec);
	void operator^=(const PrecisionDouble& sec);

	PrecisionDouble operator+(const double& sec) const;
	PrecisionDouble operator-(const double& sec) const;
	void operator+=(const double& sec);
	void operator-=(const double& sec);

	PrecisionDouble operator*(const double& sec) const;
	PrecisionDouble operator/(const double& sec) const;
	PrecisionDouble operator^(const double& sec) const;
	void operator*=(const double& sec);
	void operator/=(const double& sec);
	void operator^=(const double& sec);

	PrecisionDouble operator+(const int& sec) const;
	PrecisionDouble operator-(const int& sec) const;
	void operator+=(const int& sec);
	void operator-=(const int& sec);

	PrecisionDouble operator*(const int& sec) const;
	PrecisionDouble operator/(const int& sec) const;
	PrecisionDouble operator^(const int& sec) const;
	void operator*=(const int& sec);
	void operator/=(const int& sec);
	void operator^=(const int& sec);

	bool operator==(const PrecisionDouble& sec) const;
	bool operator!=(const PrecisionDouble& sec) const;
	bool operator<(const PrecisionDouble& sec) const;
	bool operator>(const PrecisionDouble& sec) const;
	bool operator<=(const PrecisionDouble& sec) const;
	bool operator>=(const PrecisionDouble& sec) const;

	bool operator==(const double sec) const;
	bool operator!=(const double sec) const;
	bool operator<(const double sec) const;
	bool operator>(const double sec) const;
	bool operator<=(const double sec) const;
	bool operator>=(const double sec) const;

	bool operator==(const int sec) const;
	bool operator!=(const int sec) const;
	bool operator<(const int sec) const;
	bool operator>(const int sec) const;
	bool operator<=(const int sec) const;
	bool operator>=(const int sec) const;
};
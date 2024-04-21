#include "../PrecisionDouble.h"
#include <stdexcept>
#include <cmath>
#include <string>

PrecisionDouble::PrecisionDouble() : dec(0), ex10(0) {}
PrecisionDouble::PrecisionDouble(double dec, double ex10) : dec(dec), ex10(ex10) {
	while (dec > 10 && dec != 0) {
		dec /= 10;
		ex10++;
	}
	while (dec < 1 && dec != 0) {
		dec *= 10;
		ex10--;
	}
	this->dec = dec;
	this->ex10 = ex10;
}

void PrecisionDouble::SetEx10(double ex10) { this->ex10 = ex10; }
void PrecisionDouble::SetDec(double dec) { this->dec = dec; }

PrecisionDouble PrecisionDouble::operator*(const PrecisionDouble& sec) const {

	double newDec = dec * sec.GetDec();
	double newEx10 = ex10 + sec.GetEx10();

	return Normalize(newDec, newEx10);
}

PrecisionDouble PrecisionDouble::operator/(const PrecisionDouble& sec) const {

	if (sec.GetDec() == 0) throw std::runtime_error("Division by zero is not defined.");

	double newDec = dec / sec.GetDec();
	double newEx10 = ex10 - sec.GetEx10();

	return Normalize(newDec, newEx10);
}

PrecisionDouble PrecisionDouble::operator+(const PrecisionDouble& sec) const {

	if (ex10 == sec.GetEx10()) return Normalize(dec + sec.GetDec(), ex10);

	if (ex10 > sec.GetEx10()) {
		PrecisionDouble* smaller = new PrecisionDouble(sec.GetDec(), -(ex10 - sec.GetEx10()) / 2);
		PrecisionDouble* bigger = new PrecisionDouble(dec, (ex10 - sec.GetEx10()) / 2);

		double multiplicator = ex10 - (ex10 - sec.GetEx10()) / 2;

		int sign = (multiplicator >= 0) ? 1 : -1;
		multiplicator = std::abs(multiplicator);

		int integerPart = static_cast<int>(multiplicator);
		double fractionalPart = sign * (multiplicator - integerPart);

		integerPart *= sign;

		multiplicator = fractionalPart;
		int rest = integerPart;


		double ans = (bigger->ToDouble() + smaller->ToDouble()) * std::pow(10, multiplicator);
		delete bigger;
		delete smaller;

		return Normalize(ans, rest);

	}

	if (ex10 < sec.GetEx10()) {
		return sec + PrecisionDouble(dec, ex10);
	}


	return PrecisionDouble();
}

PrecisionDouble PrecisionDouble::operator-(const PrecisionDouble& sec) const {

	if (ex10 == sec.GetEx10()) return Normalize(dec - sec.GetDec(), ex10);

	if (ex10 > sec.GetEx10()) {
		PrecisionDouble* smaller = new PrecisionDouble(sec.GetDec(), -(ex10 - sec.GetEx10()) / 2);
		PrecisionDouble* bigger = new PrecisionDouble(dec, (ex10 - sec.GetEx10()) / 2);

		double multiplicator = ex10 - (ex10 - sec.GetEx10()) / 2;

		int sign = (multiplicator >= 0) ? 1 : -1;
		multiplicator = std::abs(multiplicator);

		int integerPart = static_cast<int>(multiplicator);
		double fractionalPart = sign * (multiplicator - integerPart);

		integerPart *= sign;

		multiplicator = fractionalPart;
		int rest = integerPart;


		double ans = (bigger->ToDouble() - smaller->ToDouble()) * std::pow(10, multiplicator);

		delete bigger;
		delete smaller;

		return Normalize(ans, rest);

	}

	if (ex10 < sec.GetEx10()) {
		PrecisionDouble* bigger = new PrecisionDouble(sec.GetDec(), -(ex10 - sec.GetEx10()) / 2);
		PrecisionDouble* smaller = new PrecisionDouble(dec, (ex10 - sec.GetEx10()) / 2);

		double ans = bigger->ToDouble() - smaller->ToDouble();

		delete bigger;
		delete smaller;

		return Normalize(ans, sec.GetEx10());
	}


	return PrecisionDouble();
}


PrecisionDouble PrecisionDouble::Normalize(double decimal, double exp10) {

	if (decimal == 0) return PrecisionDouble();

	double absDecimal = std::fabs(decimal);

	while (absDecimal < 1) {
		absDecimal *= 10;
		decimal *= 10;
		exp10--;
	}

	while (absDecimal > 1) {
		absDecimal /= 10;
		decimal /= 10;
		exp10++;
	}

	return PrecisionDouble(decimal, exp10);
}

void PrecisionDouble::RemoveFractionEx10() {
	PrecisionDouble pD = NoFractionEx10(*this);
	dec = pD.GetDec();
	ex10 = pD.GetEx10();
}

PrecisionDouble PrecisionDouble::NoFractionEx10(const PrecisionDouble& pD) {
	double exp10 = pD.GetEx10();
	double decimal = pD.GetDec();

	int sign = (exp10 >= 0) ? 1 : -1;
	exp10 = std::abs(exp10);

	int integerPart = static_cast<int>(exp10);
	double fractionalPart = sign * (exp10 - integerPart);

	integerPart *= sign;

	decimal *= std::pow(10, fractionalPart);

	return PrecisionDouble(decimal, integerPart);
}

bool PrecisionDouble::operator<(const PrecisionDouble& sec) const {
	PrecisionDouble left = Normalize(*this);
	PrecisionDouble right = Normalize(sec);

	if (left.GetEx10() < right.GetEx10()) return true;
	if (left.GetEx10() > right.GetEx10()) return false;
	if (left.GetDec() < right.GetDec()) return true;
	if (left.GetDec() > right.GetDec()) return false;
	return false;
}

bool PrecisionDouble::operator==(const PrecisionDouble& sec) const {
	PrecisionDouble left = Normalize(NoFractionEx10(*this));
	PrecisionDouble right = Normalize(NoFractionEx10(sec));

	double precision = std::pow(10, -7);

	bool con1 = (std::abs(left.GetDec()) - std::abs(right.GetDec())) < precision;
	bool con2 = (std::abs(left.GetEx10()) - std::abs(right.GetEx10())) < precision;

	return con1 && con2;
}

std::string PrecisionDouble::ToString() const {
	return "Decimal: " + std::to_string(this->dec) + " Exponent 10: " + std::to_string(this->ex10);
}

PrecisionDouble PrecisionDouble::operator^(const PrecisionDouble& sec) const {
	//double decimal = std::round( std::pow(dec, sec.ToDouble()) * 1000) / 1000;
	double decimal = std::pow(dec, sec.ToDouble());
	double exponent10 = ex10 * sec.ToDouble();

	return Normalize(decimal, exponent10);
}

bool PrecisionDouble::operator>(const PrecisionDouble& sec) const { return sec < *this; }
bool PrecisionDouble::operator<=(const PrecisionDouble& sec) const { return *this < sec || *this == sec; }
bool PrecisionDouble::operator>=(const PrecisionDouble& sec) const { return *this > sec || *this == sec; }

bool PrecisionDouble::operator!=(const PrecisionDouble& sec) const { return !(*this == sec); }

bool PrecisionDouble::operator<(const double sec) const { return *this < Normalize(sec, 0); }
bool PrecisionDouble::operator>(const double sec) const { return *this > Normalize(sec, 0); }
bool PrecisionDouble::operator<=(const double sec) const { return *this <= Normalize(sec, 0); }
bool PrecisionDouble::operator>=(const double sec) const { return *this >= Normalize(sec, 0); }
bool PrecisionDouble::operator==(const double sec) const { return *this == Normalize(sec, 0); }
bool PrecisionDouble::operator!=(const double sec) const { return *this != Normalize(sec, 0); }

bool PrecisionDouble::operator<(const int sec) const { return *this < Normalize(sec, 0); }
bool PrecisionDouble::operator>(const int sec) const { return *this > Normalize(sec, 0); }
bool PrecisionDouble::operator<=(const int sec) const { return *this <= Normalize(sec, 0); }
bool PrecisionDouble::operator>=(const int sec) const { return *this >= Normalize(sec, 0); }
bool PrecisionDouble::operator==(const int sec) const { return *this == Normalize(sec, 0); }
bool PrecisionDouble::operator!=(const int sec) const { return *this != Normalize(sec, 0); }

PrecisionDouble PrecisionDouble::Normalize(double decimal) { return Normalize(decimal, 0); }
PrecisionDouble PrecisionDouble::Normalize(const PrecisionDouble& toNormalize) {
	return Normalize(toNormalize.GetDec(), toNormalize.GetEx10());
}

void PrecisionDouble::operator*=(const PrecisionDouble& sec) { *this = *this * sec; }
void PrecisionDouble::operator/=(const PrecisionDouble& sec) { *this = *this / sec; }
void PrecisionDouble::operator^=(const PrecisionDouble& sec) { *this = *this ^ sec; }

void PrecisionDouble::operator+=(const PrecisionDouble& sec) { *this = *this + sec; }
void PrecisionDouble::operator-=(const PrecisionDouble& sec) { *this = *this - sec; }

PrecisionDouble PrecisionDouble::operator+ (const double& sec) const { return *this + Normalize(sec); }
PrecisionDouble PrecisionDouble::operator- (const double& sec) const { return *this - Normalize(sec); }
PrecisionDouble PrecisionDouble::operator* (const double& sec) const { return *this * Normalize(sec); }
PrecisionDouble PrecisionDouble::operator/ (const double& sec) const { return *this / Normalize(sec); }
PrecisionDouble PrecisionDouble::operator^ (const double& sec) const { return *this ^ Normalize(sec); }
void PrecisionDouble::operator+= (const double& sec) { *this += Normalize(sec); }
void PrecisionDouble::operator-= (const double& sec) { *this -= Normalize(sec); }
void PrecisionDouble::operator*= (const double& sec) { *this *= Normalize(sec); }
void PrecisionDouble::operator/= (const double& sec) { *this /= Normalize(sec); }
void PrecisionDouble::operator^= (const double& sec) { *this ^= Normalize(sec); }


PrecisionDouble PrecisionDouble::operator+ (const int& sec) const { return *this + Normalize(sec); }
PrecisionDouble PrecisionDouble::operator- (const int& sec) const { return *this - Normalize(sec); }
PrecisionDouble PrecisionDouble::operator* (const int& sec) const { return *this * Normalize(sec); }
PrecisionDouble PrecisionDouble::operator/ (const int& sec) const { return *this / Normalize(sec); }
PrecisionDouble PrecisionDouble::operator^ (const int& sec) const { return *this ^ Normalize(sec); }
void PrecisionDouble::operator+= (const int& sec) { *this += Normalize(sec); }
void PrecisionDouble::operator-= (const int& sec) { *this -= Normalize(sec); }
void PrecisionDouble::operator*= (const int& sec) { *this *= Normalize(sec); }
void PrecisionDouble::operator/= (const int& sec) { *this /= Normalize(sec); }
void PrecisionDouble::operator^= (const int& sec) { *this ^= Normalize(sec); }

double PrecisionDouble::GetDec() const { return dec; }
double PrecisionDouble::GetEx10() const { return ex10; }

double PrecisionDouble::ToDouble() const { return dec * std::pow(10, ex10); }

PrecisionDouble PrecisionDouble::NoFractionEx10() const { return NoFractionEx10(*this); }
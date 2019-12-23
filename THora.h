#pragma once
#include<string>
#include<ctime>
using namespace std;

class THora {
protected:
	int hora, minuto;
	double segundo;
public:
	THora();
	THora(int h, int m, double s);			
	THora(const string& temp);				
	THora(const char* temp);				
	bool setHora(int h);
	bool setMinuto(int m);
	bool setSegundo(double d);
	virtual bool set(int h, int m, double s);
	virtual void set(const string& temp);	
	void operator=(const string& temp);		
	string tempo_str() const;				
	int getHora() const;
	int getMinuto() const;
	double getSegundo() const;
	double totalHoras() const;				
	double totalMinutos() const;			
	double totalSegundos() const;			
	THora operator-(const THora& outra) const; 
											   
	THora operator+(const THora& outra) const;
	bool operator<(const THora& outra) const;
	bool operator>(const THora& outra) const;
	bool operator==(const THora& outra) const;
	bool operator!=(const THora& outra) const;
	bool operator<=(const THora& outra) const;
	bool operator>=(const THora& outra) const;
	static THora agora();
private:									// Métodos estáticos auxiliares
	static bool tempoValido(int h, int m, double s);
};

ostream& operator<<(ostream& os, const THora& temp);
istream& operator>>(istream& is, THora& temp);
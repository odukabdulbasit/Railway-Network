#pragma once
#include"TData.h"
#include"THora.h"

class TDataHora : public TData, public THora {
public:
	TDataHora();
	TDataHora(int d, int m, int a, int h, int min, double s);
	TDataHora(const TData& d, const THora& t);
	TDataHora(const string& dt);			
	TDataHora(const char* dt);				
	bool set(int d, int m, int a, int h, int min, double s); 
	void set(const string& dt);				
	void setData(const TData& d);
	void setTempo(const THora& t);
	void operator=(const string& dt);		
	string datahora_str() const;					
	TData getData() const;
	THora getTempo() const;
	THora operator-(const TDataHora& outra) const; 
												   
	bool operator<(const TDataHora& outra) const;
	bool operator>(const TDataHora& outra) const;
	bool operator==(const TDataHora& outra) const;
	bool operator!=(const TDataHora& outra) const;
	bool operator<=(const TDataHora& outra) const;
	bool operator>=(const TDataHora& outra) const;
	static TDataHora hoje_agora();
};

ostream& operator<<(ostream& os, const TDataHora& dt);
istream& operator>>(istream& is, TDataHora& dt);
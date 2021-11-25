#ifndef SALES_H
#define SALES_H

class sales {
private:
	float EC;

public:
	void disparar_alarma(EC);
	void enviar_EC(EC);

	sales() = default;
	sales(float ec1);

};


#endif // !SALES_H


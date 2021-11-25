#ifndef TEMPERATURA_H
#define TEMPERATURA_H

//TURBIDEZ,PH,EC
class temperatura {

private:
	float temperaturas;
public:

	void enviar_temperatura(float temperaturas);
	void set_temperatura(temperaturas);
	temperatura() = default;
	temperatura(float temperatura1);



};


#endif // !TEMPERATURA_H

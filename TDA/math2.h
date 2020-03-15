/*Definições das estruturas*/
typedef struct _quadri QUADRI;
typedef struct _poli POLI;
typedef struct _financa FINANCA;


double calc_quadrado (double lado);
double calc_trapezio (double b1, double b2, double h);
double calc_losango (double b1, double b2);
double calc_polig_regular (double lados, double n_lado, double apot);
double calc_juros_simp (double capital, double taxa, double tempo);
double calc_mont_simp (double capital, double juros);
double calc_mont_comp (double capital, double taxa, double tempo);
// Escreva um trecho de código para fazer a criação dos novos tipos de dados conforme solicitado abaixo:
// • Horário: composto de hora, minutos e segundos.
// • Data: composto de dia, mês e ano.
// • Compromisso: composto de uma Data, Horário e texto que descreve o compromisso.


// Definição dos novos tipos de dados
typedef struct {
  int hora;
  int minutos;
  int segundos;
} Horario;

typedef struct {
  int dia;
  int mes;
  int ano;
} Data;

typedef struct {
  Data data;
  Horario horario;
  char descricao[100]; // Armazena o texto do compromisso
} Compromisso;
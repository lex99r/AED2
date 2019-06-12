typedef struct{

	int mat;
	int idade;
	char nome[81];
	char email[41];
	double coef;

} Aluno;

Aluno criaAluno(int mat, char* nome, int idade, char* email, double coef);
Aluno criaAlunoAleatorio(int maxMat, int maxCoef);
void imprimeAluno(Aluno aluno);
void gravaAluno(FILE* file, Aluno aluno);
short comparaChave(double chaveA, double chaveB);
int rmat(int max);
double rcoef(int max);
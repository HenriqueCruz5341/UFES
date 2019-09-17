/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.c
 * Author: 2019107869
 *
 * Created on 10 de Abril de 2019, 10:13
 */

#include <stdio.h>
#include <stdlib.h>

/*
 *
 */
int main(int argc, char** argv) {
    int delegacao = 0, ident = 0, n1 = 0, n2 = 0, n3 = 0, d = 0, campM = 0, campF = 0, priM = 0, priF = 0, i = 0,
            j = 0, maiM = -1, maiF = -1, menM = 11, menF = 11, idMaiM = 0,
            idMaiF = 0, idMenM = 0, idMenF = 0, delegCampM = 0, delegCampF = 0,
            somaTotDelM = 0, somaTotDelF = 0, possuiM = 0, possuiF = 0, notMa1M = 0, notMa2M = 0, notMa3M = 0,
            notMa1F = 0, notMa2F = 0, notMa3F = 0, notMa1 = 0, notMa2 = 0, notMa3 = 0, notMe1 = 0, notMe2 = 0, notMe3 = 0,
            notMe1M = 0, notMe2M = 0, notMe3M = 0, notMe1F = 0, notMe2F = 0, notMe3F = 0;
    char sexo;

    scanf("%d", &delegacao);

    for (d = 1; d <= delegacao; d++) {
        //printf("Delegacao: %d\n", d);
        ident = 0;
        idMaiF = 0;
        idMaiM = 0;
        idMenF = 0;
        idMenM = 0;
        maiM = -1;
        maiF = -1;
        menM = 11;
        menF = 11;
        somaTotDelM = 0;
        somaTotDelF = 0;
        possuiM = 0;
        possuiF = 0;
        priM = 0;
        priF = 0;
        while (ident != -1) {
            scanf("%d", &ident);
            if (ident == -1) {
                break;
            }

            scanf(" %c %d %d %d", &sexo, &n1, &n2, &n3);
            if (n1 >= n2 && n2 >= n3) {
                notMa1 = n1;
                notMa2 = n2;
                notMa3 = n3;
            } else if (n1 >= n3 && n3 >= n2) {
                notMa1 = n1;
                notMa2 = n3;
                notMa3 = n2;
            } else if (n2 >= n1 && n1 >= n3) {
                notMa1 = n2;
                notMa2 = n1;
                notMa3 = n3;
            } else if (n2 >= n3 && n3 >= n1) {
                notMa1 = n2;
                notMa2 = n3;
                notMa3 = n1;
            } else if (n3 >= n1 && n1 >= n2) {
                notMa1 = n3;
                notMa2 = n1;
                notMa3 = n2;
            } else if (n3 >= n2 && n2 >= n1) {
                notMa1 = n3;
                notMa2 = n2;
                notMa3 = n1;
            } else {
                notMa1 = n1;
                notMa2 = n2;
                notMa3 = n3;
            }
            notMe3 = notMa1;
            notMe2 = notMa2;
            notMe1 = notMa3;
            //printf("Jogador: %d %c %d %d %d\n", ident, sexo, n1, n2, n3);
            //printf("%d %d %d\n", notMa1, notMa2, notMa3);

            if (sexo == 'M') {
                if (i == 0) {
                    priM = d;
                    i++;
                }
                possuiM++;
                somaTotDelM += notMa1;
                if (notMa1 > maiM) {
                    maiM = notMa1;
                    idMaiM = ident;
                    notMa1M = notMa1;
                    notMa2M = notMa2;
                    notMa3M = notMa3;
                } else if (notMa1 == maiM) {
                    if (notMa1 > notMa1M) {
                        maiM = notMa1;
                        idMaiM = ident;
                        notMa1M = notMa1;
                        notMa2M = notMa2;
                        notMa3M = notMa3;
                    } else if (notMa1 == notMa1M) {
                        if (notMa2 > notMa2M) {
                            maiM = notMa1;
                            idMaiM = ident;
                            notMa1M = notMa1;
                            notMa2M = notMa2;
                            notMa3M = notMa3;
                        } else if (notMa2 == notMa2M) {
                            if (notMa3 > notMa3M) {
                                maiM = notMa1;
                                idMaiM = ident;
                                notMa1M = notMa1;
                                notMa2M = notMa2;
                                notMa3M = notMa3;
                            } else if (notMa3 == notMa3M) {
                                if (ident < idMaiM) {
                                    maiM = notMa1;
                                    idMaiM = ident;
                                    notMa1M = notMa1;
                                    notMa2M = notMa2;
                                    notMa3M = notMa3;
                                }
                            }
                        }
                    }
                }
                if (notMe3 < menM) {
                    menM = notMa1;
                    idMenM = ident;
                    notMe1M = notMe3;
                    notMe2M = notMe2;
                    notMe3M = notMe1;
                } else if (notMe3 == menM) {
                    if (notMe3 < notMe1M) {
                        menM = notMa1;
                        idMenM = ident;
                        notMe1M = notMe3;
                        notMe2M = notMe2;
                        notMe3M = notMe1;
                    } else if (notMe3 == notMe1M) {
                        if (notMe2 < notMe2M) {
                            menM = notMa1;
                            idMenM = ident;
                            notMe1M = notMe3;
                            notMe2M = notMe2;
                            notMe3M = notMe1;
                        } else if (notMe2 == notMe2M) {
                            if (notMe1 < notMe3M) {
                                menM = notMa1;
                                idMenM = ident;
                                notMe1M = notMe3;
                                notMe2M = notMe2;
                                notMe3M = notMe1;
                            } else if (notMe1 == notMe3M) {
                                if (ident > idMenM) {
                                    menM = notMa1;
                                    idMenM = ident;
                                    notMe1M = notMe3;
                                    notMe2M = notMe2;
                                    notMe3M = notMe1;
                                }
                            }
                        }
                    }
                }
            }
            if (sexo == 'F') {
                if (j == 0) {
                    priF = d;
                    j++;
                }
                possuiF++;
                somaTotDelF += notMa1;
                if (notMa1 > maiF) {
                    maiF = notMa1;
                    idMaiF = ident;
                    notMa1F = notMa1;
                    notMa2F = notMa2;
                    notMa3F = notMa3;
                } else if (notMa1 == maiF) {
                    if (notMa1 > notMa1F) {
                        maiF = notMa1;
                        idMaiF = ident;
                        notMa1F = notMa1;
                        notMa2F = notMa2;
                        notMa3F = notMa3;
                    } else if (notMa1 == notMa1F) {
                        if (notMa2 > notMa2F) {
                            maiF = notMa1;
                            idMaiF = ident;
                            notMa1F = notMa1;
                            notMa2F = notMa2;
                            notMa3F = notMa3;
                        } else if (notMa2 == notMa2F) {
                            if (notMa3 > notMa3F) {
                                maiF = notMa1;
                                idMaiF = ident;
                                notMa1F = notMa1;
                                notMa2F = notMa2;
                                notMa3F = notMa3;
                            } else if (notMa3 == notMa3F) {
                                if (ident < idMaiF) {
                                    maiF = notMa1;
                                    idMaiF = ident;
                                    notMa1F = notMa1;
                                    notMa2F = notMa2;
                                    notMa3F = notMa3;
                                }
                            }
                        }
                    }
                }
                if (notMe3 < menF) {
                    menF = notMa1;
                    idMenF = ident;
                    notMe1F = notMe3;
                    notMe2F = notMe2;
                    notMe3F = notMe1;
                } else if (notMe3 == menF) {
                    if (notMe3 < notMe1F) {
                        menF = notMa1;
                        idMenF = ident;
                        notMe1F = notMe3;
                        notMe2F = notMe2;
                        notMe3F = notMe1;
                    } else if (notMe3 == notMe1F) {
                        if (notMe2 < notMe2F) {
                            menF = notMa1;
                            idMenF = ident;
                            notMe1F = notMe3;
                            notMe2F = notMe2;
                            notMe3F = notMe1;
                        } else if (notMe2 == notMe2F) {
                            if (notMe1 < notMe3F) {
                                menF = notMa1;
                                idMenF = ident;
                                notMe1F = notMe3;
                                notMe2F = notMe2;
                                notMe3F = notMe1;
                            } else if (notMe1 == notMe3F) {
                                if (ident > idMenF) {
                                    menF = notMa1;
                                    idMenF = ident;
                                    notMe1F = notMe3;
                                    notMe2F = notMe2;
                                    notMe3F = notMe1;
                                }
                            }
                        }
                    }
                }
            }
        }

        if (priM) {
            delegCampM = priM;
            campM = somaTotDelM;
        }
        if (priF) {
            delegCampF = priF;
            campF = somaTotDelF;
        }
        if (somaTotDelM > campM && possuiM) {
            delegCampM = d;
            campM = somaTotDelM;
        } else if (somaTotDelM == campM && possuiM) {
            if (d < delegCampM) {
                delegCampM = d;
                campM = somaTotDelM;
            }
        }
        if (somaTotDelF > campF && possuiF) {
            delegCampF = d;
            campF = somaTotDelF;
        } else if (somaTotDelF == campF && possuiF) {
            if (d < delegCampF) {
                delegCampF = d;
                campF = somaTotDelF;
            }
        }


        if (idMaiM == 0 && idMaiF != 0) {
            printf("MELHORES ATLETAS DA DELEGACAO %d\n", d);
            printf("MASCULINO: Nenhum FEMININO: %d\n", idMaiF);
            printf("PIORES ATLETAS DA DELEGACAO %d\n", d);
            printf("MASCULINO: Nenhum FEMININO: %d\n\n", idMenF);
        } else if (idMaiF == 0 && idMaiM != 0) {
            printf("MELHORES ATLETAS DA DELEGACAO %d\n", d);
            printf("MASCULINO: %d FEMININO: Nenhum\n", idMaiM);
            printf("PIORES ATLETAS DA DELEGACAO %d\n", d);
            printf("MASCULINO: %d FEMININO: Nenhum\n\n", idMenM);
        } else if (idMaiM == 0 && idMaiF == 0) {
            printf("MELHORES ATLETAS DA DELEGACAO %d\n", d);
            printf("MASCULINO: Nenhum FEMININO: Nenhum\n");
            printf("PIORES ATLETAS DA DELEGACAO %d\n", d);
            printf("MASCULINO: Nenhum FEMININO: Nenhum\n\n");
        } else {
            printf("MELHORES ATLETAS DA DELEGACAO %d\n", d);
            printf("MASCULINO: %d FEMININO: %d\n", idMaiM, idMaiF);
            printf("PIORES ATLETAS DA DELEGACAO %d\n", d);
            printf("MASCULINO: %d FEMININO: %d\n\n", idMenM, idMenF);
        }
    }
    if (delegCampM == 0 && delegCampF != 0) {
        printf("DELEGACAO CAMPEA:\n");
        printf("MASCULINO: Nenhum FEMININO: %d\n", delegCampF);
    } else if (delegCampF == 0 && delegCampM != 0) {
        printf("DELEGACAO CAMPEA:\n");
        printf("MASCULINO: %d FEMININO: Nenhum\n", delegCampM);
    } else if (delegCampF == 0 && delegCampM == 0) {
        printf("DELEGACAO CAMPEA:\n");
        printf("MASCULINO: Nenhum FEMININO: Nenhum\n");
    } else {
        printf("DELEGACAO CAMPEA:\n");
        printf("MASCULINO: %d FEMININO: %d\n", delegCampM, delegCampF);
    }
    return 0;
}
/*
1
1 M 3 4 2
2 F 9 3 3
3 M 8 9 0
4 M 4 0 8
5 M 4 3 3
-1
 */
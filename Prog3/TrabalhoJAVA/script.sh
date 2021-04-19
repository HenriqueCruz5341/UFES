#!/bin/bash

mainclass="app.Seb"

ant compile
ant jar
capitais=("aracaju" "belem" "belo-horizonte" "boa-vista" "campo-grande" "cuiaba" "curitiba" "florianopolis" "fortaleza" "goiania" "joao-pessoa" "maceio" "manaus" "natal" "palmas" "porto-alegre" "porto-velho" "recife" "rio-branco" "rio-de-janeiro" "salvador" "sao-luis" "sao-paulo" "teresina" "vitoria" )

mkdir out
mkdir diff

cd bin
for i in ${capitais[@]} ; do
    echo "$i-cadidatos.csv $i-partidos.csv"
    java ${mainclass} ../in/${i}-candidatos.csv ../in/${i}-partidos.csv 15/11/2020 > ../out/saida-${i}.txt
done


cd ..
for i in ${capitais[@]} ; do
    diff out/saida-${i}.txt out_guilherme/saida-${i}.txt > diff/saida-${i}.txt
done
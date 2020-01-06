let numeros = [];
let listaNum = window.document.getElementById('listaNum');

function adicionar(){
    let posFim;
    let cxTexto = window.document.getElementById('txtNum');
    let num = Number(cxTexto.value);
    if(numeros.length != 0){
        posFim = numeros.length-1;
    }else{
        posFim = 0;
    }
    if(num >= 1 && num <= 100 && numeros.indexOf(num) == -1){
        numeros.push(num);
        let item = window.document.createElement('option');
        item.value = num;
        item.text = "Número: " + String(num);
        listaNum.appendChild(item);
    }else{
        window.alert('Digite um número válido!');
    }
    cxTexto.value = '';
    cxTexto.focus();
}

function remover(){
    let numRemovido = Number(listaNum[listaNum.selectedIndex].value);
    listaNum.removeChild(listaNum[listaNum.selectedIndex]);
    numeros[numeros.indexOf(numRemovido)] = numeros[numeros.length-1];
    numeros.pop();
}

function finalizar(){
    let resultado = window.document.querySelector('#resultado');
    resultado.innerHTML = '<p>Foram adicionados no total ' + String(numeros.length) + ' elementos adicionados!</p>';
    if(numeros.length > 0){
        resultado.innerHTML += '<p>O maior número da lista eh: ' + achaMaior(numeros) + '</p>';
    }
    numeros = [];
    listaNum.innerHTML = '';
}

function achaMaior(lista){
    let maior = 0;
    for(pos in lista){
        if(lista[pos] > maior){
            maior  = lista[pos];
        }
    }
    return maior;
} 
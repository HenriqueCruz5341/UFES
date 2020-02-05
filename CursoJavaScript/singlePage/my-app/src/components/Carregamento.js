import React from 'react';

export default class Carregamento extends React.Component{

    carregou() {
        let i = setTimeout(function () {
            document.querySelector('.loading').style.display = "none";
            document.querySelector('.conteudo').style.display = "block";
        }, 2000);
    }

    render(){
        return(
            <div className="loading" onLoad={this.carregou.bind(this)}>
                <img src="http://media.giphy.com/media/FwviSlrsfa4aA/giphy.gif" />
            </div>
        );
    }
}
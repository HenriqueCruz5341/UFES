import React from 'react';

export default class InformationItem extends React.Component{

    render(){
        return(
            <div className="vantagensItem">
                    <div className="vantagensItemImg">
                        <img src={this.props.image} alt="Ótima Localização" title="Espaço de primeira"/>
                    </div>
                    <div className="vantagensItemTxt">
                        {this.props.txt} <br/>
                        R$800,00
                    </div>
            </div>
        );
    }
}
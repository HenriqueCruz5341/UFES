import React from 'react';


export default class Address extends React.Component{

    render(){
        return(
            <div className="address">
                <img src="./img/contato.png" alt="WhatsApp" width="25px" height="25px"/> <strong>(XX) XXXX-XXXX</strong><br/>
                Endereço: 
            </div>
        );
    }
}
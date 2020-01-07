import React from 'react';

export default class Footer extends React.Component{

    render(){
        return(
            <div className="footer">
                <div>
                    <img src="/img/logo.png" alt="Logomarca" width="75px" height="75px"/>
                </div>
                <div>
                    Endereço<br/>
                    Telefone<br/>
                    Email
                </div>
            </div>
        );
    }
}
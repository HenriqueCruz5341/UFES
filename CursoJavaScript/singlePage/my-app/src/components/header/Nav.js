import React from 'react';
import AnchorLink from 'react-anchor-link-smooth-scroll';

export default class Nav extends React.Component{

    render(){
        return(
            <div className="nav">
                <AnchorLink href="#home" offset="50">Home</AnchorLink>
                <AnchorLink href="#photo">Fotos</AnchorLink>
                <AnchorLink href="#information">informações</AnchorLink>
                <AnchorLink href="#contact">Contato</AnchorLink>
            </div>
        );
    }
}
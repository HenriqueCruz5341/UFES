import React from 'react';
import AnchorLink from 'react-anchor-link-smooth-scroll';
import {Link} from 'react-router-dom';

export default class Nav extends React.Component{

    render(){
        return(
            <div className="nav">
                <AnchorLink href="#home" offset="50">Home</AnchorLink>
                <AnchorLink href="#mapa">Mapa</AnchorLink>
                <AnchorLink href="#information">informações</AnchorLink>
                <AnchorLink href="#contact" offset="45">Contato</AnchorLink>
            </div>
            /*<div className="nav">
                <Link to="/">Home</Link>
                <Link to="/contato">Contato</Link>
            </div>*/
        );
    }
}
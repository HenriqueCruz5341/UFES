import React from 'react';
import Header from './Header';
import Main from './Main';
import Footer from './Footer';
import Carregamento from './Carregamento';
import Contact from './main/Contact';

export default class App extends React.Component{
    render(){
        return(
            <div>
                <div className="loading">
                    <Carregamento/>
                </div>
                <div className="conteudo">
                    <Header/>
                    <Contact/>
                </div>
            </div>
        );
        
    }
}
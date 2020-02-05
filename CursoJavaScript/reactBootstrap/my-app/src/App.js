import React, {Component} from 'react';
import NavBar from './ui/NavBar';
import './App.css';

class App extends Component {
    
    render(){
        return ( 
            <div className = "container-fluid" >
                <NavBar logo='Meu Site'/>
            </div>
        );
    }
}

export default App;
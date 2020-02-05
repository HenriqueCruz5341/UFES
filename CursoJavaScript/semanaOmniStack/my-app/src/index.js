import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import App from './App';
import { BrowserRouter, Switch, Route} from 'react-router-dom'
import Perfil from './pages/perfil';

ReactDOM.render(
    <BrowserRouter>
        <Switch>
            <Route path="/" exact={true} component={App}/>
            <Route path="/profile" exact={true} component={Perfil}/>
        </Switch>
    </BrowserRouter>, 
    document.getElementById('root'));

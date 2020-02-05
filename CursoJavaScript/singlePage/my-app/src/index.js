import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import App from './components/App';
import Contato from './components/Contato';
import { BrowserRouter, Switch, Route} from 'react-router-dom';

ReactDOM.render(
    <BrowserRouter>
        <Switch>
            <Route path="/" exact={true} component={App}/>
            <Route path="/contato" exact={true} component={Contato}/>
        </Switch>
    </BrowserRouter>,
    document.getElementById("root")
);
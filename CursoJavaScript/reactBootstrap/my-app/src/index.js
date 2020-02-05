import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import App from './App';
import * as serviceWorker from './serviceWorker';
import { BrowserRouter, Switch, Route} from 'react-router-dom'
import Home from './container/Home';
import Releases from './container/Releases';
import Backlogs from './container/Backlogs';
import Sprints from './container/Sprints';


ReactDOM.render(
    <BrowserRouter>
        <App/>
        <Switch>
            <Route exact path="/" component={Home}/>
            <Route path="/releases" component={Releases}/>
            <Route path="/backlogs" component={Backlogs}/>
            <Route path="/sprints" component={Sprints}/>
        </Switch>
    </BrowserRouter>
    , 
    document.getElementById('root'));

// If you want your app to work offline and load faster, you can change
// unregister() to register() below. Note this comes with some pitfalls.
// Learn more about service workers: https://bit.ly/CRA-PWA
serviceWorker.unregister();

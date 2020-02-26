import React from 'react';
import Header from './Components/Header/Header';
import Footer from './Components/Footer/Footer';
import { BrowserRouter, Switch, Route} from 'react-router-dom';
import Home from './Components/Pages/Home/Home';
import Schedule from './Components/Pages/Schedule/Schedule';
import Events from './Components/Pages/Events/Events';

function App() {
  return (
    <div className="App">
      <BrowserRouter>
        <Header/>
        <Switch>
          <Route exact={true} path="/" component={Home}/>
          <Route exact={true} path="/cronograma" component={Schedule}/>
          <Route exact={true} path="/eventos" component={Events}/>
        </Switch>
        <Footer/>
      </BrowserRouter>
    </div>
  );
}

export default App;

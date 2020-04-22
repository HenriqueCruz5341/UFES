import React from 'react';
import './App.css';
import Nav from "./components/Navbar/Nav";
import Footer from "./components/Footer/Footer";
import About from "./components/About/About";
import Schedule from "./components/Schedule/Schedule";
import Projects from "./components/Projects/Projects";
import Contact from "./components/Contact/Contact";
import Documents from "./components/Documents/Documents";
import Home from "./components/Home/Home";
import ItemDetail from "./components/Documents/ItemDetail"
import { BrowserRouter as Router, Switch, Route } from "react-router-dom";

function App() {
  return (
    <div className="App">
      <Router>
        <Nav/>
        <Switch>
          <Route path="/" exact component={Home} />
          <Route path="/about" component={About} />
          <Route path="/documents" exact component={Documents} />
          <Route path="/documents/:id" component={ItemDetail} />
          <Route path="/schedule" exact component={Schedule} />
          <Route path="/projects" exact component={Projects} />
          <Route path="/contact" exact component={Contact} />
        </Switch>
        <Footer/>
      </Router>
    </div>
  );
}





export default App;

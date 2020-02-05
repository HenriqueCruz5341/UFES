import React from 'react';
import {Link} from 'react-router-dom';

const NavBar = (props) => {
    return (
    <nav className="navbar navbar-expand-lg navbar-light bg-light">
        <Link to="/" className="navbar-brand">{props.logo}</Link>
        <button className="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
            <span className="navbar-toggler-icon"></span>
        </button>

        <div className="collapse navbar-collapse" id="navbarSupportedContent">
            <ul className="navbar-nav mr-auto">
                <li className="nav-item">
                    <Link to="/releases" className="nav-link">Releases</Link>
                </li>
                <li className="nav-item">
                    <Link to="/backlogs" className="nav-link">Backlogs</Link>
                </li>
                <li className="nav-item dropdown">
                    <Link to="/sprints" className="nav-link">Sprints</Link>
                </li>
            </ul>
        <form className="form-inline my-2 my-lg-0">
            <input className="form-control mr-sm-2" type="search" placeholder="Search" aria-label="Search"/>
            <button className="btn btn-outline-success my-2 my-sm-0" type="submit">Search</button>
        </form>
        </div>
    </nav>
    );
};

export default NavBar;
import React from 'react';
import {Link} from 'react-router-dom';

const HomeCard = (props) =>{
    return(
        <div className="col sm-4 d-flex" style={{display: "flex", marginTop: "24px", justifyContent: "center"}}>
            <div className="card" style={{width: '18rem'}}>
                <img src={props.img} className="card-img-top rounded mx-auto d-block" alt="..." style={{padding: '5px'}}/>
                <div className="card-body">
                    <h5 className="card-title">{props.title}</h5>
                    <p className="card-text">{props.text}</p>
                    <Link to={props.url}><button className="btn btn-primary">Go to {props.title}</button></Link>
                </div>
            </div>
        </div>
    );
}

export default HomeCard;
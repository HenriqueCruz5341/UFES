import React, { useState, useEffect } from 'react';
import './perfil.css';
import {Button} from 'react-bootstrap';
import api from '../services/api';

function Perfil(props){
    let dev = props.location.state;
    const [techs, setTechs] = useState('');
    const [name, setName] = useState('');

    useEffect(() => {
        setName(dev.name);
        setTechs(dev.techs.join(', '));
    }, [dev.name, dev.techs]);

    async function updateProfile(e){
        e.preventDefault();

        let data = {
            github_username: dev.github_username,
            techs,
            name
        }

        await api.put(`/devs`, data);

        let nameCampo = document.querySelector("#name");
        nameCampo.innerHTML = `${name}`;
        let techsCampo = document.querySelector("#techs");
        techsCampo.innerHTML = `${techs}`;
    }

    function updateName(){
        let nameCampo = document.querySelector("#name");
        nameCampo.innerHTML = `<input value="${name}" type="text" name="name" id="inputName" required/>`;
        let inputName = document.querySelector("#inputName");
        inputName.addEventListener("change", e => setName(e.target.value));
    }

    function updateTechs(dev){
        let techsCampo = document.querySelector("#techs");
        techsCampo.innerHTML = `<input value="${techs}" type="text" name="techs" id="inputTechs" required/>`;
        let inputTechs = document.querySelector("#inputTechs");
        inputTechs.addEventListener("change", e => setTechs(e.target.value));
    }

    return(
        <div className="perfil">
            <form onSubmit={updateProfile}>
                <header>
                    <img src={dev.avatar_url} alt={dev.name}/>
                    <div className="users-info">
                        <strong>
                            <span id="name">
                                {name}
                            </span>
                            <div className="updateName" onClick={updateName}>
                                <svg className="bi bi-pencil" width="20px" height="20px" viewBox="0 0 20 20" fill="currentColor" xmlns="http://www.w3.org/2000/svg">
                                    <path fillRule="evenodd" d="M13.293 3.293a1 1 0 011.414 0l2 2a1 1 0 010 1.414l-9 9a1 1 0 01-.39.242l-3 1a1 1 0 01-1.266-1.265l1-3a1 1 0 01.242-.391l9-9zM14 4l2 2-9 9-3 1 1-3 9-9z" clipRule="evenodd"></path>
                                    <path fillRule="evenodd" d="M14.146 8.354l-2.5-2.5.708-.708 2.5 2.5-.708.708zM5 12v.5a.5.5 0 00.5.5H6v.5a.5.5 0 00.5.5H7v.5a.5.5 0 00.5.5H8v-1.5a.5.5 0 00-.5-.5H7v-.5a.5.5 0 00-.5-.5H5z" clipRule="evenodd"></path>
                                </svg>
                            </div>
                        </strong>
                        
                        <div className="listaTechs">
                        <span id="techs">
                            {techs}
                        </span>
                            <div className="updateTechs" onClick={updateTechs}>
                                <svg className="bi bi-pencil" width="20px" height="20px" viewBox="0 0 20 20" fill="currentColor" xmlns="http://www.w3.org/2000/svg">
                                    <path fillRule="evenodd" d="M13.293 3.293a1 1 0 011.414 0l2 2a1 1 0 010 1.414l-9 9a1 1 0 01-.39.242l-3 1a1 1 0 01-1.266-1.265l1-3a1 1 0 01.242-.391l9-9zM14 4l2 2-9 9-3 1 1-3 9-9z" clipRule="evenodd"></path>
                                    <path fillRule="evenodd" d="M14.146 8.354l-2.5-2.5.708-.708 2.5 2.5-.708.708zM5 12v.5a.5.5 0 00.5.5H6v.5a.5.5 0 00.5.5H7v.5a.5.5 0 00.5.5H8v-1.5a.5.5 0 00-.5-.5H7v-.5a.5.5 0 00-.5-.5H5z" clipRule="evenodd"></path>
                                </svg>
                            </div>
                        </div>
                    </div>
                </header>
                <p>{dev.bio}</p>
                <div className="options">
                    <Button type="submit">Salvar</Button>
                </div>
            </form>
        </div>
    );
}

export default Perfil;
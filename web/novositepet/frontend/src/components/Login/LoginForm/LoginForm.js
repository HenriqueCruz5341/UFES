import React, { useState } from "react";
import { MDBContainer, MDBBtn, MDBTabPane, MDBTabContent } from "mdbreact";
import "./LoginForm.css"
import styled from "styled-components"

function Login(props) {
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");
  const [validLogin, setValidLogin] = useState("");
  const [activeItem, setActiveItem] = useState("1");

 

  async function handleLogin(e) {
    e.preventDefault();
    
  }

  return (
    <MDBTabContent activeItem={activeItem}>
      <MDBTabPane tabId="1" role="tabpanel">
        <form onSubmit={handleLogin}>
          <MDBContainer>
            <label htmlFor="iemail" className="grey-text">
              E-mail
            </label>
            <input
              id="iemail"
              className={`form-control ${validLogin}`}
              type="email"
              value={email}
              onChange={(e) => setEmail(e.target.value)}
              required
            />

            <label htmlFor="ipassword" className="grey-text">
              Senha
            </label>
            <input
              id="ipassword"
              type="password"
              className={`form-control ${validLogin}`}
              value={password}
              onChange={(e) => setPassword(e.target.value)}
              required
            />
            
            <div className="text-center mt-4">
              <MDBBtn type="submit">
                Confirmar
              </MDBBtn>
            </div>
          </MDBContainer>
        </form>
      </MDBTabPane>
    </MDBTabContent>
  );
}

export default Login;

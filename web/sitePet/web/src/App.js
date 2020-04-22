import React, { useState, useEffect } from "react";
import axios from "axios";
import api from "./api";

import { Inscription, FiDownloadS, FiXCircleS } from "./style";

function App() {
  const [name, setName] = useState("");
  const [email, setEmail] = useState("");
  const [phone, setPhone] = useState("");
  const [file, setFile] = useState();
  const [inscriptions, setInscriptions] = useState([]);

  async function getInscriptions() {
    const response = await api.get("/api/inscriptions/");
    setInscriptions(response.data.inscriptions);
    console.log(response.data.inscriptions);
  }

  useEffect(() => {
    getInscriptions();
  }, []);

  const handleDownload = (inscription) => {
    axios({
      url:
        "http://localhost:3333/api/file/download/" + inscription.documents._id,
      method: "GET",
      responseType: "blob",
    }).then((response) => {
      const url = window.URL.createObjectURL(new Blob([response.data]));
      const link = document.createElement("a");
      const fileName =
        inscription.name.replace(" ", "") + "-" + inscription.documents.name;
      link.setAttribute("href", url);
      link.setAttribute("download", fileName);
      document.body.appendChild(link);
      link.click();
    });
  };

  const handleDelete = async (inscription) => {
    try {
      await api.delete(`/api/inscriptions/${inscription._id}`);
      getInscriptions();
    } catch (err) {
      window.alert("Erro! " + err.response);
    }
  };

  const handleSubmit = async (e) => {
    e.preventDefault();
    if (file) {
      const formData = new FormData();

      formData.append("file", file);
      formData.append("name", name);
      formData.append("email", email);
      formData.append("phone", phone);

      try {
        await api.post("/api/inscriptions/", formData);
        getInscriptions();
      } catch (err) {
        console.log(err.response);
      }
    }
  };

  return (
    <div className="App">
      <form onSubmit={handleSubmit}>
        <label>Name</label>
        <input
          type="text"
          value={name}
          onChange={(e) => setName(e.target.value)}
        />

        <br />
        <label>Email</label>
        <input
          type="text"
          value={email}
          onChange={(e) => setEmail(e.target.value)}
        />

        <br />
        <label>Phone</label>
        <input
          type="text"
          value={phone}
          onChange={(e) => setPhone(e.target.value)}
        />

        <br />
        <label>Documentos</label>
        <input type="file" onChange={(e) => setFile(e.target.files[0])} />

        <br />
        <button type="submit">Submit</button>
      </form>
      {inscriptions.map((inscription) => (
        <Inscription key={inscription._id}>
          <div>
            <p>Name: {inscription.name}</p>
            <p>Email: {inscription.email}</p>
            <p>Phone: {inscription.phone}</p>
          </div>
          <div style={{ position: "relative", width: "30px" }}>
            <FiDownloadS onClick={() => handleDownload(inscription)} />
            <FiXCircleS onClick={() => handleDelete(inscription)} />
          </div>
        </Inscription>
      ))}
    </div>
  );
}

export default App;

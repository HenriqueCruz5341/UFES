import React, { useState, useEffect } from "react";
import api from "./api";

import { Noticia, FiXCircleS } from "./newsStyle";

function News() {
  const [title, setTitle] = useState("");
  const [text, setText] = useState("");
  const [file, setFile] = useState();
  const [news, setNews] = useState([]);

  async function getNews() {
    const response = await api.get("/api/news/");
    setNews(response.data.news);
    console.log(response.data.news);
  }

  useEffect(() => {
    getNews();
  }, []);

  const handleDelete = async (n) => {
    try {
      await api.delete(`/api/news/${n._id}`);
      getNews();
    } catch (err) {
      window.alert("Erro! " + err.response);
    }
  };

  const handleSubmit = async (e) => {
    e.preventDefault();
    if (file) {
      const formData = new FormData();
      console.log(title, text, file);
      formData.append("file", file);
      formData.append("title", title);
      formData.append("text", text);

      try {
        await api.post("/api/news/", formData, {
          headers: {
            Authorization:
              "Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJfaWQiOjEyMzQ1NiwiaWF0IjoxNTg4NjI3MzgxfQ.3wNyVGPvlKJWjn4KQzJcQW4yPVjoeyZFnWwOu5_C3tQ",
          },
        });
        getNews();
      } catch (err) {
        console.log(err.response);
      }
    }
  };

  return (
    <div className="App">
      <form onSubmit={handleSubmit}>
        <label>Title</label>
        <input
          type="text"
          value={title}
          onChange={(e) => setTitle(e.target.value)}
        />

        <br />
        <label>Text</label>
        <input
          type="textarea"
          value={text}
          onChange={(e) => setText(e.target.value)}
        />

        <br />
        <label>Image</label>
        <input type="file" onChange={(e) => setFile(e.target.files[0])} />

        <br />
        <button type="submit">Submit</button>
      </form>
      {news.map((n) => {
        console.log(n);
        return (
          <Noticia key={n._id}>
            <div>
              <p>Title: {n.title}</p>
              <p>Text: {n.text}</p>
              <p>
                Image:{" "}
                <img
                  alt="imagem qualquer"
                  //   esse 'http://' é de extrema importancia
                  src={`http://localhost:3333/api/file/getImage/${n.file._id}`}
                />
              </p>
            </div>
            <div style={{ position: "relative", width: "30px" }}>
              <FiXCircleS onClick={() => handleDelete(n)} />
            </div>
          </Noticia>
        );
      })}
    </div>
  );
}

export default News;

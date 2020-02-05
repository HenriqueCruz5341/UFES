import React, {useEffect, useState} from 'react';
import './App.css';
import './global.css';
import './SideBar.css';
import './Main.css';
import './services/api';
import api from './services/api';
import DevItem from './components/DevItem';
import DevForm from './components/DevForm';

function App() {
  const [devs, setDevs] = useState([]);

  useEffect(() => {
    async function loadDevs(){
      const response = await api.get('/devs');

      setDevs(response.data);
    }

    loadDevs();
  }, []);

  async function handleAddDev(data){
    const response = await api.post('/devs', data);

    setDevs([...devs, response.data]);
  }

  function updateListDev(data){
    setDevs(data);
  }

  return (
    <div className="app">
      <aside>
        <strong>Cadastrar</strong>
        <DevForm onSubmit={handleAddDev} />
      </aside>
      <main>
        <ul>
          {devs.map(dev => (
          <DevItem key={dev._id} dev={dev} excluir={updateListDev.bind(this)}/>  
          ))}
        </ul>
      </main>
    </div>
  );
}

export default App;

import React from 'react';
import {Modal, Button} from 'react-bootstrap';
import api from '../../services/api';


function ModalDelete(props) {
    const {dev} = props;
    let name;

    if(!dev.name){
        name = dev.github_username;
    }else{
        name = dev.name;
    }

    async function handleDeleteDev(e){
        e.preventDefault();

        await api.delete(`/delete?github_username=${dev.github_username}`);
        const responseList = await api.get('/devs');
        
        await props.excluir(responseList.data);
    }

    return (
      <Modal {...props} size="lg" aria-labelledby="contained-modal-title-vcenter" centered>
        <Modal.Header closeButton>
          <Modal.Title id="contained-modal-title-vcenter">
            Você está prestes a excluir um Dev
          </Modal.Title>
        </Modal.Header>
        <Modal.Body>
    <h4>Tem certeza que deseja excluir {name}?</h4>
          <p>
            Este Dev tem várias qualidades, ele conhece tecnologias como: {dev.techs.join(', ')}
          </p>
        </Modal.Body>
        <Modal.Footer>
            <form onSubmit={handleDeleteDev}>
                <Button onClick={props.onHide} className="btn-danger" type="submit">Excluir</Button>
            </form>
        </Modal.Footer>
      </Modal>
    );
}

export default ModalDelete;
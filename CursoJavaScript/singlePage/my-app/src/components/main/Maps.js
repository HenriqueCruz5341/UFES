import React from 'react';

export default class Maps extends React.Component{

    render(){
        return(
            <div className="mapsImovel" id="mapa">
                <iframe src="https://www.google.com/maps/embed?pb=!1m14!1m12!1m3!1d11486.324221311032!2d15.6518903034254!3d43.96803190444149!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!5e0!3m2!1spt-BR!2sbr!4v1578418833259!5m2!1spt-BR!2sbr" allowfullscreen=""></iframe>
            </div>
        );
    }
}
import React from 'react';
import InformationItem from './InformationItem';

export default class Information extends React.Component{

    render(){
        const div1={
            image: "https://i.picsum.photos/id/342/50/50.jpg",
            txt: "Ótimo apartamento com extrutura de primeira."
        }

        return(
            <div className="information" id="information">
                <ul>
                    <li>2 Quartos, sendo 1 suíte</li>
                    <li>1 Cozinha grande</li>
                    <li>Varanda com vista para a praia</li>
                    <li>1 banheiro social</li>
                </ul>
                <div className="vantagens">
                    <InformationItem {...div1}/>
                    <InformationItem image="https://i.picsum.photos/id/343/50/50.jpg" txt="Apartamento show."/>
                    <InformationItem image="https://i.picsum.photos/id/344/50/50.jpg" txt="Apartamento Top."/>
                </div>
            </div>
        );
    }
}
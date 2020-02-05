import React, {Component} from 'react';
import ReleaseForm from '../ui/ReleaseForm';

export default class Releases extends Component{

    constructor(){
        super();
        this.handleSubmit = this.handleSubmit.bind(this);
        this.state = {
            releases: [
                {
                    id: 1,
                    releaseName: 'Release 01',
                    releaseDate: '01/01/2020'
                },
                {
                    id: 2,
                    releaseName: 'Release 02',
                    releaseDate: '02/02/2020'
                },
                {
                    id: 3,
                    releaseName: 'Release 03',
                    releaseDate: '03/03/2020'
                },
                {
                    id: 4,
                    releaseName: 'Release 04',
                    releaseDate: '04/04/2020'
                },
            ]
        }
    }

    handleSubmit(e){
        console.log('Print here');
    }

    render(){
        return(
            <div className="container">
                <ReleaseForm submitHandler={this.handleSubmit}/>
                <table className="table table-hover">
                    <thead>
                        <tr>
                        <th scope="col">#</th>
                        <th scope="col">Name</th>
                        <th scope="col">Date</th>
                        <th scope="col">Options</th>
                        </tr>
                    </thead>
                    <tbody>
                        {this.state.releases.map((release, index) => {
                            return(
                                <tr key={release.id}>
                                    <th scope="row">{release.id}</th>
                                    <td>{release.releaseName}</td>
                                    <td>{release.releaseDate}</td>
                                    <td>
                                        <button type="button" class="btn btn-warning">Editar</button>
                                        <button type="button" class="btn btn-danger">Excluir</button>
                                    </td>
                                </tr>
                            );
                        })}
                    </tbody>
                </table>
            </div>
        );
    }
}
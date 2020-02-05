import React, {Component} from 'react';
import HomeCard from '../ui/HomeCard';
import { Redirect } from 'react-router-dom';

export default class Home extends Component{

    homeCardReleases = {
        title: 'Releases',
        img: 'https://i.picsum.photos/id/1014/100/100.jpg',
        text: 'Manage Releases',
        url: '/releases'
    }
    homeCardBacklog = {
        title: 'Backlogs',
        img: 'https://i.picsum.photos/id/1015/100/100.jpg',
        text: 'Manage Backlogs',
        url: '/backlogs'
    }
    homeCardSprints = {
        title: 'Sprints',
        img: 'https://i.picsum.photos/id/1016/100/100.jpg',
        text: 'Manage Sprints',
        url: '/sprints'
    }

    render(){
        return(
            <div className="container">
                <div className="row">
                    <HomeCard {...this.homeCardReleases}/>
                    <HomeCard {...this.homeCardBacklog}/>
                    <HomeCard {...this.homeCardSprints}/>
                </div>
            </div>
        );
    }
}
import React, {  useState, useEffect } from 'react'
import {Link} from "react-router-dom"
function Item({match}){
           
        useEffect(() =>{ 
            fetchItem()
            console.log(match)
        },[])
    
        const [item,setItem] = useState([])

        const fetchItem = async ()=>{
            console.log(match.params.id)
        }
        
      return (
            <div>
                <h1>Item</h1>
            </div>
        )
    
}

export default Item

import React from "react";
import { MDBPopover, MDBPopoverBody, MDBPopoverHeader, MDBBtn } from "mdbreact";

const Popover = (props) => {
  let color;
  if(props.type === 'minicurso'){
    color = 'yellow';
  }else if(props.type === 'palestra'){
    color = 'blue';
  }else if(props.type === 'workshop'){
    color = 'red';
  }

  return (
        <MDBPopover
          placement="top"
          popover
          clickable
          id="popper1"
        >
          <MDBBtn color={color}>{props.name}</MDBBtn>
          <div>
            <MDBPopoverHeader className="headPopover">{props.type}</MDBPopoverHeader>
            <MDBPopoverBody>
              {props.text}
            </MDBPopoverBody>
          </div>
        </MDBPopover>
  );
}

export default Popover;
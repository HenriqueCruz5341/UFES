import React from "react";
import { MDBPopover, MDBPopoverHeader, MDBBtn } from "mdbreact";

const Popover = props => {
  let color;
  if (props.type === "Aula teórica") {
    color = "yellow";
  } else if (props.type === "Palestra") {
    color = "blue";
  } else if (props.type === "Minicurso prático") {
    color = "red";
  }

  return (
    <MDBPopover placement="top" popover clickable id="popper1">
      <MDBBtn color={color} size="sm">
        {props.name}
      </MDBBtn>
      <div>
        <MDBPopoverHeader className="headPopover">
          {props.type}
        </MDBPopoverHeader>
      </div>
    </MDBPopover>
  );
};

export default Popover;

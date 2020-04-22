import React, { useState } from "react";
import {
  MDBRow,
  MDBCol,
  MDBTabPane,
  MDBTabContent,
  MDBNavItem,
  MDBNavLink,
} from "mdbreact";
import "./profile.css";
import EditProfile from "./EditProfile/EditProfile";
import SetPersonalSchedule from "./SetPersonalSchedule/SetPersonalSchedule";
import UnenrollEvents from "./UnenrollEvents/UnenrollEvents";
import StudentProvider from "../../../Contexts/Student";
import { ToastProvider } from "react-toast-notifications";
import { MDBNavS, MDBContainerS } from "./style";

function Profile() {
  const [activeItem, setActiveitem] = useState("0");
  const [activeOption, setActiveOption] = useState(["activeTab", "", ""]);

  function changeActive(id) {
    if (id !== activeItem) {
      let vetAux = [];
      for (let i = 0; i < 3; i++) {
        if (i !== Number.parseInt(id)) vetAux[i] = "";
        else vetAux[i] = "activeTab";
      }
      setActiveitem(id);
      setActiveOption(vetAux);
    }
  }

  return (
    <StudentProvider>
      <ToastProvider autoDismiss autoDismissTimeout={5000}>
        <MDBContainerS>
          <MDBRow>
            <MDBCol md="3" style={{ justifyContent: "start" }}>
              <MDBNavS pills className="flex-column">
                <MDBNavItem>
                  <MDBNavLink
                    to="#"
                    active={activeItem === "0"}
                    onClick={() => changeActive("0")}
                    role="tab"
                    className={`buttonSideMenu ${activeOption[0]}`}
                  >
                    Informações
                  </MDBNavLink>
                </MDBNavItem>
                <MDBNavItem>
                  <MDBNavLink
                    to="#"
                    active={activeItem === "1"}
                    onClick={() => changeActive("1")}
                    role="tab"
                    className={`buttonSideMenu ${activeOption[1]}`}
                  >
                    Montar Grade
                  </MDBNavLink>
                </MDBNavItem>
                <MDBNavItem>
                  <MDBNavLink
                    to="#"
                    active={activeItem === "2"}
                    onClick={() => changeActive("2")}
                    role="tab"
                    className={`buttonSideMenu ${activeOption[2]}`}
                  >
                    Minhas Inscriçoes
                  </MDBNavLink>
                </MDBNavItem>
              </MDBNavS>
            </MDBCol>
            <MDBCol md="9" style={{ justifyContent: "start" }}>
              <MDBTabContent activeItem={activeItem} style={{ width: "100%" }}>
                <MDBTabPane tabId="0" role="tabpanel">
                  <EditProfile />
                </MDBTabPane>
                <MDBTabPane tabId="1" role="tabpanel">
                  <SetPersonalSchedule />
                </MDBTabPane>
                <MDBTabPane tabId="2" role="tabpanel">
                  <UnenrollEvents />
                </MDBTabPane>
              </MDBTabContent>
            </MDBCol>
          </MDBRow>
        </MDBContainerS>
      </ToastProvider>
    </StudentProvider>
  );
}

export default Profile;

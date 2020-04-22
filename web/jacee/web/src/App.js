import React from "react";
import "./global.css";
import Header from "./Components/Header/Header";
import Footer from "./Components/Footer/Footer";
import { BrowserRouter, Switch, Route, Redirect } from "react-router-dom";
import Home from "./Components/Pages/Home/Home";
import Schedule from "./Components/Pages/Schedule/Schedule";
import Events from "./Components/Pages/Events/Events";
import EventsAdmin from "./Components/Pages/AdminsPage/EventsAdmin/EventsAdmin";
import RegisterEvents from "./Components/Pages/AdminsPage/EventsAdmin/RegisterEvents/RegisterEvents";
import InspecEvents from "./Components/Pages/AdminsPage/EventsAdmin/InspecEvents/InspecEvents";
import isAuth from "./services/Auth";
import Logout from "./services/Logout";
import Profile from "./Components/Pages/Profile/Profile";
import StudentsAdmin from "./Components/Pages/AdminsPage/StudentsAdmin/StudentsAdmin";
import InspecStudents from "./Components/Pages/AdminsPage/StudentsAdmin/InspectStudents/InspectStudents";
import AdminsList from "./Components/Pages/AdminsPage/AdminsList/AdminsList";
import RegisterAdmin from "./Components/Pages/AdminsPage/AdminsList/RegisterAdmin/RegisterAdmin";
import UpdateEvent from "./Components/Pages/AdminsPage/EventsAdmin/UpdateEvent/UpdateEvent";
import MarkPresence from "./Components/Pages/AdminsPage/MarkPresence/MarkPresence";
import MarkPresenceEvent from "./Components/Pages/AdminsPage/MarkPresence/MarkPresenceEvent/MarkPresenceEvent";

const AdminRoute = ({ component: Component, ...rest }) => {
  return (
    <Route
      {...rest}
      render={(props) =>
        isAuth() ? (
          <Component {...props} />
        ) : (
          <Redirect to={{ pathname: "/" }} />
        )
      }
    />
  );
};

const StudentRoute = ({ component: Component, ...rest }) => {
  return (
    <Route
      {...rest}
      render={(props) =>
        !isAuth() ? (
          <Component {...props} />
        ) : (
          <Redirect to={{ pathname: "/" }} />
        )
      }
    />
  );
};

function App() {
  return (
    <div className="App">
      <BrowserRouter>
        <Header />
        <Switch>
          <Route exact={true} path="/" component={Home} />
          <Route exact={true} path="/cronograma" component={Schedule} />
          <Route exact={true} path="/eventos" component={Events} />
          <Route exact={true} path="/logout" component={Logout} />
          <StudentRoute exact={true} path="/perfil" component={Profile} />
          <AdminRoute
            exact={true}
            path="/eventsAdmin"
            component={EventsAdmin}
          />
          <AdminRoute
            exact={true}
            path="/eventsAdmin/register"
            component={RegisterEvents}
          />
          <AdminRoute
            exact={false}
            path="/eventsAdmin/inspect/"
            component={InspecEvents}
          />
          <AdminRoute
            exact={false}
            path="/eventsAdmin/update/"
            component={UpdateEvent}
          />
          <AdminRoute
            exact={true}
            path="/studentsAdmin"
            component={StudentsAdmin}
          />
          <AdminRoute
            exact={false}
            path="/studentsAdmin/inspect/"
            component={InspecStudents}
          />
          <AdminRoute exact={true} path="/adminsList" component={AdminsList} />
          <AdminRoute
            exact={true}
            path="/adminsList/register"
            component={RegisterAdmin}
          />
          <AdminRoute
            exact={true}
            path="/markPresence"
            component={MarkPresence}
          />
          <AdminRoute
            exact={false}
            path="/markPresence/"
            component={MarkPresenceEvent}
          />
          <Redirect from="*" to="/" />
        </Switch>
        <Footer />
      </BrowserRouter>
    </div>
  );
}

export default App;

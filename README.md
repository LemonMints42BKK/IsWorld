<h1>cub3d</h1>
<div>
    <a href="#tasks">project tasks</a><br>
    <a href="#subject">cub3d subject(ภาษาไทย)</a>
</div>
<h3 class="tasks">-ลำดับการทำงาน-</h3>
    <div>
        <ol>
            <li>เช็คจำนวนอาร์กิวเมนต์และรูปแบบให้ตรงกับที่อยู่ไฟล์แผนที่</li>
            <li>เช็คข้อมูลในไฟล์แผนที่ว่าสามารถดำเนินการต่อไปได้หรือไม่ หากข้อมูลถูกด้องให้จัดเก็บในรูปแบบตัวแปรตามโครงสร้าง และชนิดที่กำหนดขึ้น(t_frame)</li>
            <li>จัดเก็บค่าทางกราฟฟิก ได้แก่ mlx และ win ลงในตัวแปร vars ชนิด t_var</li>
            <li>...</li>
        </ol>
    </div>
<h3 class="subject">-ภาคบังคับ-<a href="https://github.com/LemonMints42BKK/42Projects/blob/1360cedce734dfe0ab88df36f24d7280e82f67ac/Rank04/cub3D/en.subject.pdf">English</a></h3>
    <p> พฤษจิกายน ๒๕๖๖ <p>
    <div>
      <ul>
        <li>เลือกใช้ miniLibX ให้ตรงกับระบบปฎิบัติการคอมพิวเตอร์ที่แสดงผลโปรแกรม สร้างแหล่งที่มาของชุดคำสั่งโค้ช(ไลบรารี่)ในโปรแกรมนี้เช่นเดียวกับชุดคำสั่งโค้ช(ไลบรารี่)ของlibft </li>
        <li>ตั้งค่าการจัดการหน้าต่าง(Window)ให้สามารถ เลือกเปลี่ยนหน้าต่างอื่น ย่อขยาย ฯลฯ</li>
        <li>แสดงพื้นผิวของผนัง(ตามต้องการ)ให้แตกต่างกันไป ขึ้นอยู่กับว่าผนังนั้นหันหน้าไปทางทิศใด(เหนือ(NOrth) ใต้(SOuth) ตะวันออก(EAst) ตะวันตก(WEst)</li>
        <li>โปรแกรมสามารถตั้งค่าสีพื้นและสีเพดานให้แตกต่างกัน</li>
        <li>โปรแกรมแสดงภาพในหน้าต่าง ตามกฏเกญฑ์ดังนี้
          <ul>
              <li>การกดปุ่มลูกศรซ้ายและขวาบนแป้นพิมพ์ เพื่อปรับการมองเห็นทางซ้ายและทางขวาภายในเขาวงกต</li>
              <li>การกดปุ่ม W, A, S และ D เพื่อย้ายมุมมอง(เคลื่อนที่)ภายเขาวงกต</li>
              <li>การกดปุ่ม ESC เพื่อปิดหน้าต่างและออกจากโปรแกรมโดยสมบูรณ์</li>
              <li>การกดที่กากบาทสีแดงบนกรอบหน้าต่างเพื่อปิดหน้าต่างและออกจากโปรแกรมโดยสมบูรณ์</li>
              <li>ใช้การแสดงผลภาพผ่านโปรแกรม minilibX เท่านั้น</li>
          </ul>
        </li>
        <li>โปรแกรมต้องรับอาร์กิวเมนต์แรกเป็นชื่อไฟล์ที่มีนามสกุล .cub เพื่อเรียกใช้ข้อมูลส่วนประกอบฉาก
          <ul>
              <li>แผนที่จะต้องประกอบด้วยอักขระได้เพียง 6 ตัว: 0 แทนพื้นที่ว่าง 1 แทนกำแพง ส่วน N,S,E หรือ W สำหรับตำแหน่งเริ่มต้นของผู้เล่นและการวางตัวละคร
นี่คือตัวอย่างแผนที่ที่ถูกต้อง
              <p>
                111111<br>
                100101<br>
                101001<br>
                1100N1<br>
                111111<br>
              </p>
              </li>
              <li>แผนที่จะต้องปิด/ล้อมรอบด้วยกำแพง หากเป็นไม่เช่นนั้นโปรแกรมจะต้องแจ้งข้อผิดพลาด</li>
              <li>สำหรับเนื้อหาส่วนที่ไม่ใช่แผนที่ แต่ละองค์ประกอบสามารถคั่นด้วยบรรทัดว่างได้มากกว่าหนึ่งบรรทัด</li>
              <li>เนื้อหาส่วนแผนที่จะต้องอยู่ส่วนสุดท้ายของไฟล์เสมอ และองค์ประกอบอื่นสามารถจัดลำดับอย่างไรก็ได้ในไฟล์</li>
              <li>ข้อมูลขององค์ประกอบแต่ละประเภท(ยกเว้นแผนที่) ควรคั่นด้วยช่องว่างอย่างน้อยหนึ่งช่องเสมอ</li>
              <li>การวิเคราะห์แผนที่ในไฟล์ ช่องว่างสามารถเป็นส่วนหนึ่งของแผนที่ิได้ โดยแล้วแต่คุณจะเลือกวิธีจัดการ คุณสามารถแยกวิเคราะห์แผนที่อย่างไรก็ได้ ตราบใดที่เคารพกฎการเขียนแผนที่</li>
              <li>ข้อมูลของแต่ละองค์ประกอบ(ยกเว้นส่วนแผนที่) ข้อมูลอันดับแรกคือตัวระบุประเภท (ประกอบด้วยอักขระหนึ่งหรือสองตัว) ตามด้วยข้อมูลเฉพาะทั้งหมดสำหรับแต่ละวัตถุตามลำดับ ดังนี้:
                <ul>
                  <li>NO: พื้นผนังทิศเหนือ(north texture) ตามด้วยการระบุที่อยู่ไฟล์<br>NO ./path_to_the_north_texture</li>
                  <li>SO: พื้นผนังทิศใต้(sorth texture) ตามด้วยการระบุที่อยู่ไฟล์<br>SO ./path_to_the_south_texture</li>
                  <li>WE: พื้นผนังทิศตะวันตก(west texture) ตามด้วยการระบุที่อยู่ไฟล์<br>WE ./path_to_the_west_texture</li>
                  <li>EA: พื้นผนังทิศตะวันออก(east texture) ตามด้วยการระบุที่อยู่ไฟล์<br>EA ./path_to_the_east_texture</li>
                  <li>F: สีพื้น(floor color) ตามด้วยตัวเลขค่าสี R,G,B ในช่วงระหว่าง[0-255]<br>F 220,100,0</li>
                  <li>C: สีเพดาน(ceilling color) ตามด้วยตัวเลขค่าสี R,G,B ในช่วงระหว่าง[0-255]<br>C 225,30,0</li>
                </ul>
              </li>
              <li>ตัวอย่างของไฟล์ฉากภาคบังคับ .cub เบื้องต้น:<br>
                <img alt=".cub exsample" src="https://github.com/LemonMints42BKK/42Projects/blob/f82b670668eaab46ba87765120a1903269621919/Rank04/cub3D/Screen%20Shot%202566-11-11%20at%2015.02.58.png">
              </li>
              <li>หากพบการกำหนดค่าที่ไม่ถูกต้องใดๆ ในไฟล์ โปรแกรมจะต้องออกอย่างถูกต้องและส่งกลับ "Error\n" ตามด้วยข้อความแสดงข้อผิดพลาดที่ชัดเจนที่คุณเลือก</li>
          </ul>
        </li>
      </ul>
    </div>
    <div>
      <h3>cub3D-ภาคเสริม</h3>
      <p>รายการภาคเสริม</p>
        <ul>
            <li>ผนังถูกทำร้าย</li>
            <li>ระบบแผนที่นำทาง</li>
            <li>ประตูสามารถเปิด-ปิดได้</li>
            <li>sprites(ศัตรู หรือวัตถุประกอบฉาก) เคลื่อนไหว</li>
            <li>การหมุนมุมมองด้วยเมาส์</li>
        </ul>
    </div>
